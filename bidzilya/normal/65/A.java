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
	
	long nod(long x,long y){
		while (x>0 && y>0)
			if (x>=y)
				x %= y;
			else 
				y %= x;
		return x+y;
	}
	
	public void solve(){
		long a = in.nextLong(),
			b = in.nextLong(),
			c = in.nextLong(),
			d = in.nextLong(),
			e = in.nextLong(),
			f = in.nextLong(),
			nod,nok;
		if (a==0 || b==0 || c==0 || d==0 || e==0 || f==0){
			if (d!=0 && (c==0 || c!=0 && a==0 && b!=0))
				out.println("Ron");
			else
			if (d==0)
				out.println("Hermione");
			else
			if(a!=0 && b!=0 && c!=0 && d!=0 && e==0 && f!=0)
				out.println("Ron");
			else
				out.println("Hermione");
			return;
		}
		nod = nod(a,b);
		nod = nod(nod,c);
		nod = nod(nod,d);
		nod = nod(nod,e);
		nod = nod(nod,f);
		nok = a*b*c*d*e*f/nod;
		long t = nok;
		t = nok/a*b;
		t = t/c*d;
		t = t/e*f;
		if (t>nok)
			out.println("Ron");
		else
			out.println("Hermione");
		
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