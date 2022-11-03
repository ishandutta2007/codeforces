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
	private InputReader in;
	private PrintWriter out;
	Solver(InputReader in, PrintWriter out){
		this.in = in;
		this.out = out;
	}
	
	public void solve(){
		int n = in.nextInt(),
				t1=in.nextInt(),
				t2=in.nextInt(),
				k=in.nextInt();
		k = 100-k;
		int a[] = new int[n];
		for (int i=0;i<n;i++){
			int x=in.nextInt(),
					y=in.nextInt();
			a[i]=Math.max(x*t1*k+y*t2*100,y*t1*k+x*t2*100);
		}
		int ind[] = new int[n];
		for (int i=0;i<n;i++)
			ind[i]=i+1;
		for (int i=0;i<n-1;i++)
			for (int j=i+1;j<n;j++)
				if (a[j]>a[i] || a[j]==a[i] && ind[j]<ind[i]){
					int buf=a[i];a[i]=a[j];a[j]=buf;
					buf=ind[i];ind[i]=ind[j];ind[j]=buf;
				}
		for (int i=0;i<n;i++){
			int d = Math.round(a[i]/100),
			    c1 = ((int)a[i]/10)%10,
			    c2 = a[i]%10;
			out.println(ind[i] + " " + d + "." + c1 + c2);
		}
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