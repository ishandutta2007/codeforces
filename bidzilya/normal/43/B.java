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
	
	private static final int size = 'z'-'a'+1;
	
	private void stringToChar(String s, int a[], int b[]){
		for (int i=0;i<s.length();i++){
			char c = s.charAt(i);
			if (c>='A' && c<='Z')
				b[c-'A']++;
			else
			if (c>='a' && c<='z')
				a[c-'a']++;
		}
	}
	
	public void solve(){
		String s1=in.nextLine(),
			   s2=in.nextLine();
		int a[] = new int[size],
			A[] = new int[size],
			b[] = new int[size],
			B[] = new int[size];
		
		stringToChar(s1, a, A);
		stringToChar(s2, b, B);
		boolean ok1 = true,
				ok2 = true;
		for (int i=0;i<size;i++){
			if (a[i]<b[i]){
				ok1 = false;
				break;
			}
			if (A[i]<B[i]){
				ok2 = false;
				break;
			}
		}
		if (ok1 && ok2)
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
	
	public String nextLine(){
		try{
			return buf.readLine();
		}catch (IOException e){
			throw new RuntimeException(e);
		}
	}
}