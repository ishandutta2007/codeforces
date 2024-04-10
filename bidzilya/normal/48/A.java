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
	
	boolean isPaper(String s){
		return s.equals("paper");
	}
	
	boolean isRock(String s){
		return s.equals("rock");
	}
	
	boolean isBlade(String s){
		return s.equals("scissors");
	}
	
	boolean win(String s1, String s2, String s3){
		return (isRock(s1) && isBlade(s2) && isBlade(s3) ||
				isBlade(s1) && isPaper(s2) && isPaper(s3) ||
				isPaper(s1) && isRock(s2) && isRock(s3));
	}
	
	public void solve(){
		String 
			s1 = in.nextLine(),
			s2 = in.nextLine(),
			s3 = in.nextLine();
		if (win(s1,s2,s3))
				out.println("F");
		else
		if (win(s2,s1,s3))
				out.println("M");
		else
		if (win(s3,s1,s2))
				out.println("S");
		else
				out.println("?");
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