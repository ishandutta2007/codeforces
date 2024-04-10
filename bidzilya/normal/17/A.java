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
	
	private boolean isPrime(int x){
		for (int i=2;i<=Math.round(Math.sqrt(x));i++)
			if (x%i==0)
				return false;
		return true;
	}
	
	public void solve(){
		int n=in.nextInt(),
			k=in.nextInt(),
			prime[] = new int[1000],
			m=0;
		for (int i=2;i<=n;i++)
			if (isPrime(i))
				prime[m++]=i;
		
		int ans = 0;
	  for (int i=2;i<m;i++)
		  for (int j=1;j<i;j++)
			  if (prime[i]==prime[j]+prime[j-1]+1){
				  ans++;
				  break;
			  }
		
		if (ans>=k)
			out.println("YES");
		else
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