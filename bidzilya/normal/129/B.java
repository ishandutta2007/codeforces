import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.StringTokenizer;

public class Task {

	public static void main(String args[]){
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		InputReader in = new InputReader(inputStream);
		
		Solver s = new Solver(in,out);
		s.solve();
		
		out.close();
	}
}

class Solver{
	InputReader in;
	PrintWriter out;
	
	public void solve(){
		boolean isR[][]=new boolean[100][100];
		int cnt[] = new int[100];
		int n=in.nextInt(),
			m=in.nextInt();
		for (int i=0;i<m;i++){
			int a=in.nextInt(),
				b=in.nextInt();
			a--;b--;
			isR[a][b]=true;
			isR[b][a]=true;
			cnt[a]++;
			cnt[b]++;
		}
		int ta =0;
		for (int i=0;i<n;i++){
			boolean del[] = new boolean[100];
			for (int j=0;j<n;j++)
				if (cnt[j]==1)
					del[j]=true;
			boolean ok = false;
			for (int j=0;j<n;j++)
				if (del[j]){
					ok = true;
					cnt[j]=0;
					for (int k=0;k<n;k++)
						if (isR[j][k]){
							isR[j][k]=false;
							isR[k][j]=false;
							cnt[k]--;
						}
				}
			ta += (ok)?1:0;
		}
		
		out.println(ta);
	}

		
	Solver(InputReader in, PrintWriter out){
		this.in=in;
		this.out=out;
	}
}

class InputReader{
	private BufferedReader buf;
	private StringTokenizer tok;
	
	InputReader(InputStream in){
		tok = null;
		buf = new BufferedReader(new InputStreamReader(in));
	}
	
	public String next(){
		while (tok==null || !tok.hasMoreTokens()){
			try{
				tok = new StringTokenizer(buf.readLine());
			}catch (IOException e){
				throw new RuntimeException(e);
			}
		}
		return tok.nextToken();
	}
	
	public int nextInt(){
		return Integer.parseInt(next());
	}
	
	public long nextLong(){
		return Long.parseLong(next());
	}
	
	public double nextDouble(){
		return Double.parseDouble(next());
	}
	
	public float nextFloat(){
		return Float.parseFloat(next());
	}
	
	public String nextLine(){
		try{
			return buf.readLine();
		}catch (IOException e){
			throw new RuntimeException(e);
		}
	}
}