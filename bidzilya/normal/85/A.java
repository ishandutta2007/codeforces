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
	
	private char getSim(int sim){
		return (char)(sim+'a');
	}

	public void solve(){
		int n=in.nextInt();
		char a[][] = new char[4][n];
		if (n%2==1){
			int sim=0;
			for (int i=0;i<n-1;i+=2){
				a[0][i]=getSim(sim);
				a[0][i+1]=a[0][i];
				sim = (sim+1)%2;
			}
			a[0][n-1]=getSim(sim);
			a[1][n-1]=a[0][n-1];
			sim = (sim+1)%2;
			for (int i=n-1;i>0;i-=2){
				a[2][i]=getSim(sim);
				a[2][i-1]=a[2][i];
				sim = (sim+1)%2;
			}
			for (int i=n-2;i>=0;i-=2){
				a[1][i]=getSim(sim+2);
				a[1][i-1]=a[1][i];
				sim = (sim+1)%2;
			}
			a[2][0]=getSim(sim+2);
			a[3][0]=a[2][0];
			sim = (sim+1)%2;
			for (int i=1;i<n;i+=2){
				a[3][i]=getSim(sim+2);
				a[3][i+1]=a[3][i];
				sim = (sim+1)%2;
			}
		}
		else{
			int sim=0;
			for (int i=0;i<n;i+=2){
				a[0][i]=getSim(sim);
				a[0][i+1]=a[0][i];
				sim = (sim+1)%2;
			}
			a[1][n-1]=getSim(sim+5);
			a[2][n-1]=a[1][n-1];
			sim = (sim+1)%2;
			for (int i=n-1;i>=0;i-=2){
				a[3][i]=getSim(sim);
				a[3][i-1]=a[3][i];
				sim = (sim+1)%2;
			}
			a[2][0]=getSim(sim+10);
			a[1][0]=a[2][0];
			for (int i=1;i<n-1;i+=2){
				a[1][i]=getSim(sim+2);
				a[1][i+1]=a[1][i];
				sim = (sim+1)%2;
			}
			for (int i=n-2;i>=1;i-=2){
				a[2][i]=getSim(sim+2);
				a[2][i-1]=a[2][i];
				sim = (sim+1)%2;
			}
		}
		for (int i=0;i<4;i++){
			for (int j=0;j<n;j++)
				out.print(a[i][j]);
			out.println();
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