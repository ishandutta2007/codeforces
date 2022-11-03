import java.util.Random;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.File;
import java.math.BigInteger;

public class Task{
	
	static final boolean readFromFile = true;
	static final String fileInputName = "input.txt",
						fileOutputName = "output.txt";
	
	public static void main(String args[]){
		FileInputStream fileInputStream;
		FileOutputStream fileOutputStream;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (readFromFile){
			try{
				fileInputStream = new FileInputStream(new File(fileInputName));
				fileOutputStream = new FileOutputStream(new File(fileOutputName));
			}catch (FileNotFoundException e){
				throw new RuntimeException(e);
			}
		}
		PrintWriter out = new PrintWriter((readFromFile)?fileOutputStream:outputStream);
		InputReader in  = new InputReader((readFromFile)?fileInputStream:inputStream);
		
		Solver s = new Solver(in, out);
		s.solve();
		
		out.close();
	}
}

class Solver{
	private PrintWriter out;
	private InputReader in;
	
	boolean sr(int a, int b, int c, int d, int e, int f){
		if (a==d && b==e && c==f ||
			a==d && b==f && c==e ||
			a==e && b==d && c==f ||
			a==e && b==f && c==d ||
			a==f && b==d && c==e ||
			a==f && b==e && c==d)
			return true;
		return false;
	}
	
	public void solve(){
		int n = in.nextInt(),
			m = in.nextInt(),
			str[] = new int[n],
			stl[] = new int[m];
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++){
				int a = in.nextInt();
				str[i]+=a;
				stl[j]+=a;
			}
		int a = in.nextInt(),
			b = in.nextInt(),
			c = in.nextInt();
		for (int i=1;i<n;i++)
			str[i] = str[i-1]+str[i];
		for (int i=1;i<m;i++)
			stl[i] = stl[i-1]+stl[i];
		int ans = 0;
		
		for (int i=0;i<n;i++)
			for (int j=i+2;j<n;j++){
				int sumA = str[i],
					sumB = str[j-1]-str[i],
					sumC = str[n-1]-str[j-1];
				if (sr(sumA,sumB,sumC,a,b,c))
					ans++;
			}
		for (int i=0;i<m;i++)
			for (int j=i+2;j<m;j++){
				int sumA = stl[i],
					sumB = stl[j-1]-stl[i],
					sumC = stl[m-1]-stl[j-1];
				if (sr(sumA,sumB,sumC,a,b,c))
					ans++;

			}
		out.println(ans);
	}
	
	Solver(InputReader in, PrintWriter out){
		this.in = in;
		this.out = out;
	}
}

class InputReader{
	StringTokenizer tok;
	BufferedReader buf;
	
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