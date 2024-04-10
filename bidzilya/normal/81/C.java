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
import java.util.Random;
import java.util.StringTokenizer;

public class Task {

	private static final boolean readFromFile = false;
	private static final String fileInputName = "input.txt",
								fileOutputName = "output.txt";
	
	public static void main(String args[]){
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FileOutputStream fileOutputStream;
		FileInputStream fileInputStream;
		if (readFromFile){
			try{
				fileInputStream = new FileInputStream(new File(fileInputName));
				fileOutputStream = new FileOutputStream(new File(fileOutputName));
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
		int n = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		if (a==b){
			for (int i=0;i<a;i++)
				out.print("1 ");
			for (int i=0;i<a;i++)
				out.print("2 ");
			return;
		}
		int A[] = new int[n];
		int ans[] = new int[n];
		Arrays.fill(ans,-1);
		for (int i=0;i<n;i++)
			A[i]=in.nextInt();
		if (a<b){
			for (int j=5;j>=1;j--)
				for (int i=0;i<n;i++)
					if (a>0 && A[i]==j){
						a--;
						ans[i]=1;
					}
			for (int i=0;i<n;i++)
				if (ans[i]==-1)
					ans[i]=2;
			for (int i=0;i<n;i++)
				out.print(ans[i] + " ");
		}else{
			for (int j=5;j>=1;j--)
				for (int i=n-1;i>=0;i--)
					if (b>0 && A[i]==j){
						b--;
						ans[i]=2;
					}
			for (int i=0;i<n;i++)
				if (ans[i]==-1)
					ans[i]=1;
			for (int i=0;i<n;i++)
				out.print(ans[i] + " ");
		}
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