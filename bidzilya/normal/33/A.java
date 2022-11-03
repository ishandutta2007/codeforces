import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Task {

	private static final boolean readFromFile = false;
	
	public static void main(String args[]){
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FileOutputStream fileOutputStream;
		FileInputStream fileInputStream;
		if (readFromFile){
			try{
				fileInputStream = new FileInputStream(new File("input.txt"));
				fileOutputStream = new FileOutputStream(new File("output.txt"));
			}catch (FileNotFoundException e){
				throw new RuntimeException(e);
			}
		}
		PrintWriter out = new PrintWriter((readFromFile)?fileOutputStream:outputStream);
		InputReader in = new InputReader((readFromFile)?fileInputStream:inputStream);
		
		Solver s = new Solver(in,out);
		s.solve();
		
		out.close();
	}
}

class Solver{
	InputReader in;
	PrintWriter out;
	
	public void solve(){
		int n=in.nextInt();
		int m=in.nextInt();
		int k=in.nextInt();
		int a[] = new int[m];
		Arrays.fill(a, Integer.MAX_VALUE);
		for (int i=0;i<n;i++){
			int r=in.nextInt();
			int l=in.nextInt();
			r--;
			a[r]=Math.min(a[r],l);
		}
		int ans =0;
		for (int i=0;i<m;i++)
			ans += a[i];
		ans = Math.min(ans,k);
		out.println(ans);
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
	
	InputReader(FileInputStream in){
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
			return null;
		}
	}
}