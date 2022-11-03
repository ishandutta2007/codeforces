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
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class Main{
	
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
	 
	
	int v[],n,m,c[],ans=0,v1[],v2[],max[];
	boolean is[];
	
	void dfs(int tv, int maxcost){
		if (v[tv]==-1){
			max[ans]=maxcost;
			v2[ans]=tv;
			return;
		}
		dfs(v[tv],Math.min(maxcost, c[tv]));
	}
	
	public void solve(){
		int n = in.nextInt(),
			m = in.nextInt();
		v = new int[n];
		c = new int[n];
		is = new boolean[n];
		Arrays.fill(v, -1);
		for (int i=0;i<m;i++){
			int a = in.nextInt(),
				b = in.nextInt(),
				d = in.nextInt();
			a--;b--;
			v[a] = b;
			c[a] = d;
			is[b] = true;
		}
		v1 = new int[n];
		v2 = new int[n];
		max = new int[n];
		for (int i=0;i<n;i++)
			if (!is[i] && v[i]!=-1){
				v1[ans] = i;
				dfs(i,Integer.MAX_VALUE);
				ans++;
			}
		out.println(ans);
		for (int i=0;i<ans;i++)
			out.println((v1[i]+1) + " " + (v2[i]+1) + " " + max[i]);
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