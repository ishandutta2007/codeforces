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
	
	public void solve(){
		int n=in.nextInt();
		int m=in.nextInt();
		int k=in.nextInt();
		int t=in.nextInt();
		int Count[] = new int[n+1];
		int Head[] = new int[n+1];
		int Next[] = new int[k];
		int T[] = new int[k];
		Arrays.fill(Head, -1);
		for (int i=0;i<k;i++){
			int y=in.nextInt();
			int x=in.nextInt();
			Next[i]=Head[y];
			Head[y]=i;
			T[i]=x;
			Count[y]++;
		}
		for (int i=1;i<=n;i++)
			Count[i]=m-Count[i];
		for (int i=0;i<t;i++){
			int y=in.nextInt();
			int x=in.nextInt();
			int pos = x;
			
			boolean isLife = true;
			int j = Head[y];
			while (j!=-1){
				if (T[j]==x){
					isLife=false;
					break;
				}else
				if (T[j]<x)
					pos--;
				j=Next[j];
			}
			
			for (j=1;j<y;j++)
				pos+=Count[j];
			if (!isLife)
				out.println("Waste");
			else
				switch (pos%3){
				case 0: out.println("Grapes");break;
				case 1: out.println("Carrots");break;
				case 2: out.println("Kiwis");break;
				}
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