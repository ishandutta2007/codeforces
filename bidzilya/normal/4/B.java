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
		int q[] = new int[240*30],
			l[] = new int[240*30],
			p[] = new int[240*30],
			maxTime[] = new int[30],
			minTime[] = new int[30],
			ps = 0,
			pe = 0,
			n = in.nextInt(),
			sumTime = in.nextInt();
		boolean us[][] = new boolean[30][241];
		
		for (int i=0;i<n;i++){
			minTime[i]=in.nextInt();
			maxTime[i]=in.nextInt();
		}
		
		for (int i=minTime[0];i<=maxTime[0];i++){
			l[pe]=0;
			p[pe]=-1;
			q[pe++]=i;
		}
		
		while (ps<pe){
			if (l[ps]==n-1 && q[ps]==sumTime){
				int ans[] = new int[30],
					m = 0;
				for (int i=ps;i!=-1;i=p[i])
					ans[m++] = (l[i]==0)?q[i]:q[i]-q[p[i]];
				out.println("YES");
				for (int i=m-1;i>=0;i--)
					out.print(ans[i] + " ");
				return;
			}
			int u = l[ps]+1,
				sum = q[ps];
			
			ps++;
			if (u>=n)
				continue;
			for (int i=minTime[u];i<=maxTime[u];i++)
				if (!us[u][sum+i]){
					us[u][sum+i]=true;
					l[pe]=u;
					q[pe]=sum+i;
					p[pe++]=ps-1;
				}
		}
		out.println("NO");
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
}