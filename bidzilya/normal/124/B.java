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
	
	int perm[];
	char a[][],b[][];
	int n,k,ans;
	boolean us[];
	
	void build(){
		b = new char[n][k];
		for (int i=0;i<n;i++)
			for (int j=0;j<k;j++)
				b[i][j]=a[i][perm[j]];
	}
	
	void check(){
		int m[] = new int[n];
		for (int i=0;i<n;i++)
			m[i]=Integer.parseInt(new String(b[i]));
		int maxValue = 0,
			minValue = Integer.MAX_VALUE;
		for (int i=0;i<n;i++){
			maxValue = Math.max(maxValue, m[i]);
			minValue = Math.min(minValue, m[i]);
		}
		ans = Math.min(ans, maxValue-minValue);
	}
	
	void dfs(int v){
		if (v==k){
			build();
			check();
			return;
		}
		for (int i=0;i<k;i++)
			if (!us[i]){
				us[i]=true;
				perm[v]=i;
				dfs(v+1);
				us[i]=false;
			}
	}
	
	public void solve(){
		n = in.nextInt();
		k = in.nextInt();
		a = new char[n][k];
		for (int i=0;i<n;i++){
			String temp = in.nextLine();
			a[i] = temp.toCharArray();
		}
		
		perm = new int[k];
		us = new boolean[k];
		ans = Integer.MAX_VALUE;
		dfs(0);
		
		out.println(ans);
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