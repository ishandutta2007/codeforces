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
	
	private int nod(int a, int b){
		while (a>0 && b>0)
			if (a>b)
				a %= b;
			else
				b %= a;
		return a+b;
	}
	
	public void solve(){
		int n=in.nextInt();
		String ss=in.nextLine(),
			   tt=in.nextLine();
		StringBuilder s = new StringBuilder(ss),
			   t = new StringBuilder(tt);	
				
		int k = s.length()*t.length()/nod(s.length(),t.length());
		while (s.length()<k) s.append(ss);
		while (t.length()<k) t.append(tt);
		int countRound = n/k,
			countAfterRound = n%k;
		int ansRound1=0,
			ansRound2=0;
		for (int i=0;i<s.length();i++){
			char c1 = s.charAt(i),
				 c2 = t.charAt(i);
			if (c1==c2)
				continue;
			else
			if (c1=='R' && c2=='S' || c1=='S' && c2=='P' || c1=='P' && c2=='R')
				ansRound2++;
			else
				ansRound1++;
		}
		int ans1 = ansRound1*countRound,
		    ans2 = ansRound2*countRound;
		for (int i=0;i<countAfterRound;i++){
			char c1 = s.charAt(i),
				 c2 = t.charAt(i);
			if (c1==c2)
				continue;
			else
			if (c1=='R' && c2=='S' || c1=='S' && c2=='P' || c1=='P' && c2=='R')
				ans2++;
			else
				ans1++;
		}
		out.println(ans1 + " " + ans2);
		
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