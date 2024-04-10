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
	
	private long b[];
	private static final long mod = 1000000007;
	
	private long[] ymn(long a[], long b[]){
		long c[] = new long[4];
		c[0]=a[0]*b[0]+a[1]*b[2];
		c[1]=a[0]*b[1]+a[1]*b[3];
		c[2]=a[2]*b[0]+a[3]*b[2];
		c[3]=a[2]*b[1]+a[3]*b[3];
		c[0]=c[0]%mod;
		c[1]=c[1]%mod;
		c[2]=c[2]%mod;
		c[3]=c[3]%mod;
		return c;
	}
	
	private long[] Binary(long st){
		if (st==1)
			return b;
		if (st%2==0){
			long temp[] = Binary((long)st/2);
			return ymn(temp, temp);
		}
		return ymn(Binary(st-1),b);
	}
	
	public void solve(){
		long n=in.nextLong();
		if (n==0){
			out.println("1");
			return;
		}
		b = new long[4];
		b[0]=b[3]=3;
		b[1]=b[2]=1;
		b = Binary(n);
		out.println(b[0]);
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