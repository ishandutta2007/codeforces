import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.StringTokenizer;

public class Task{
	
	static final boolean readFromFile = false;
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
	
	static final double eps = 1e-8;
	
	double ans,a[],maxAi;
	int k,n;
	boolean found;
	
	public void updateAnswer(double newAns){
		if (!found || newAns<ans)
			ans = newAns;
	}
	
	public boolean may(double tekA){
		double b = 0.0,
				sum = 0.0;
		for (int i=0;i<n;i++)
			if (a[i]>tekA){
				sum += tekA;
				b += a[i]-tekA;
			}else
				sum += a[i];
		return (sum+b*k/100+eps>=tekA*n);
	}
	
	public void binary(){
		double l = 0, r = maxAi;
		while (r-l>eps){
			double m = (r+l)/2;
			if (may(m)){
				updateAnswer(m);
				l = m+eps;
			}else
				r = m-eps;
		}
	}
	
	public void solve(){
		n = in.nextInt();
		k = in.nextInt();
		k = 100-k;
		a = new double[n];
		for (int i=0;i<n;i++)
			a[i] = in.nextDouble();
		maxAi = a[0];
		for (int i=1;i<n;i++)
			maxAi = Math.max(maxAi, a[i]);
		found = false;
		
		binary();
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