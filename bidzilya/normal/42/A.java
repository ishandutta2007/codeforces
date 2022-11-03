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
	
	static final double eps = 1e-7;
	double a[],b[];
	double ans = 0;
	int n;
	
	boolean may(double x){
		double c[] = new double[n];
		double forOne = x/a[0];
		for (int i=0;i<n;i++)
			c[i]=forOne*a[i];
		for (int i=0;i<n;i++)
			if (c[i]>b[i])
				return false;
		double sum = 0;
		for (int i=0;i<n;i++)
			sum += c[i];
		ans = Math.max(sum, ans);
		return true;
	}
	
	void binarySearch(double l, double r){
		while (r-l>eps){
			double m = (l+r)/2;
			if (may(m))
				l = m+eps;
			else
				r = m-eps;
		}
	}
	
	public void solve(){
		n = in.nextInt();
		double v = in.nextDouble();
		a = new double[n];
		b = new double[n];
		
		for (int i=0;i<n;i++)
			a[i] = in.nextDouble();
		for (int i=0;i<n;i++)
			b[i] = in.nextDouble();
		binarySearch(0,b[0]);
			
		out.println(Math.min(ans, v));
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