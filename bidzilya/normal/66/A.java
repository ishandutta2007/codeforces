import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
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
	
	private String maxbyte = "127",
				maxshort = "32767",
				maxint = "2147483647",
				maxlong = "9223372036854775807";
	
	private boolean sr(String s1, String s2){
		if (s1.length()<s2.length())
			return true;
		if (s1.length()>s2.length())
			return false;
		for (int i=0;i<s1.length();i++){
			char c1 = s1.charAt(i),
				c2 = s2.charAt(i);
			if (c1<c2)
				return true;
			else
			if (c1>c2)
				return false;
		}
		return true;
	}
	
	public void solve(){
		String s = in.nextLine();
		if (s.charAt(0)=='-'){
			s = s.substring(1);
			maxbyte = maxbyte.substring(0,maxbyte.length()-1) + "8";
			maxshort = maxshort.substring(0,maxshort.length()-1)+"8";
			maxint = maxint.substring(0,maxint.length()-1)+"8";
			maxlong = maxlong.substring(0,maxlong.length()-1)+"8";
		}
		if (sr(s,maxbyte))
			out.println("byte");
		else
		if (sr(s,maxshort))
			out.println("short");
		else
		if (sr(s,maxint))
			out.println("int");
		else
		if (sr(s,maxlong))
			out.println("long");
		else
			out.println("BigInteger");
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