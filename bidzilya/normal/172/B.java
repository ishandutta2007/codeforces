import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
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
	private int a,b,m;
	
	private int nextNum(int r){
		return (a*r + b)%m;
	}
	
	public void solve(){
		a = in.nextInt();
		b = in.nextInt();
		m = in.nextInt();
		int r0=in.nextInt();
		
		int u[] = new int[m];
		Arrays.fill(u, -1);
		
		r0 = nextNum(r0);
		u[r0] = 0;
		
		for (int i=1;i<=m;i++){
			int r = nextNum(r0);
			if (u[r]!=-1){
				out.print(i-u[r]);
				return;
			}
			u[r]=i;
			r0=r;
		}
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