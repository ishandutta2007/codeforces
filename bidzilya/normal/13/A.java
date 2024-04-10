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
	
	private int Sum(int x, int base){
		int res =0;
		while (x>0){
			res = res+x%base;
			x = (int)x/base;
		}
		return res;
	}
	
	public void solve(){
		int n = in.nextInt(),
			sum=0;
		for (int i=2;i<=n-1;i++)
			sum += Sum(n,i);
			
		int sum2 = n-2;
		for (int i=2;i<=Math.max(sum2,sum);i++)
			while(sum%i==0 && sum2%i==0){
				sum /= i;
				sum2 /= i;
			}
		out.println(sum + "/" + sum2);
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