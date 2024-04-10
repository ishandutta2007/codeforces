import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.StringTokenizer;

public class MyTask{
	
	public static void main(String args[]){
		OutputStream outputstream = System.out;
		InputStream inputstream = System.in;
		PrintWriter out = new PrintWriter(outputstream);
		InputReader in = new InputReader(inputstream); 
		
		Solver s = new Solver(in, out);
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
	
	private final double eps = 1e-6;
	
	private boolean may(double t, double tt){
		return (t+eps>=tt);
	}
	
	public void solve(){
		int n = in.nextInt(),
			k = in.nextInt();
		double t = in.nextDouble()/100.0;
			
		double tt = 1.0;
		int a[] = new int[n];
		for (int i=0;i<n;i++)
			a[i]=k;
		int y=n-1;
		while (!may(t,tt)){
			tt -= (1.0/(n*k));
			a[y]--;
			if (a[y]==0)
				y--;
		}
		for (int i=0;i<n;i++)
			out.print(a[i] + " ");
	}
}

class InputReader{
	private BufferedReader buf;
	private StringTokenizer tok;
	
	InputReader(InputStream in){
		buf = new BufferedReader(new InputStreamReader(in));
		tok = null;
	}
	
	public String next(){
		while (tok==null || !tok.hasMoreTokens())
			tok = new StringTokenizer(nextLine());
		return tok.nextToken();
	}
	
	public int nextInt(){
		return Integer.parseInt(next());
	}
	
	public long nextLong(){
		return Long.parseLong(next());
	}
	
	public String nextLine(){
		try{
			return buf.readLine();
		}catch (IOException e){
			throw new RuntimeException();
		}
	}
	
	public Double nextDouble(){
		return Double.parseDouble(next());
	}
	
	public Float nextFloat(){
		return Float.parseFloat(next());
	}
}