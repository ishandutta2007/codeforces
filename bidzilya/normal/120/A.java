import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.FileInputStream;
import java.io.FileOutputStream;

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
	
	public void solve(){
		Scanner sc;
		PrintWriter pw;
		try{
			sc = new Scanner(new File("input.txt"));
			pw = new PrintWriter(new File("output.txt"));
		}catch (FileNotFoundException e){
			sc = new Scanner(System.in);
			pw = new PrintWriter(System.out);
		}
		String s = sc.nextLine();
		int a = sc.nextInt();
		
		final String t = "front";
		if (s.equals(t)){
			if (a==1)
				pw.println("L");
			else
				pw.println("R");
		}
		else{
			if (a==2)
				pw.println("L");
			else
				pw.println("R");
		}
		pw.close();
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