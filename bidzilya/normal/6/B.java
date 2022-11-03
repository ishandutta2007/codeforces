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
	
	private static final int dx[] = {-1,0,0,1},
						 dy[] = {0,1,-1,0};
	
	public void solve(){
		int n = in.nextInt(),
			m = in.nextInt();
		char p = in.nextChar();
		char map[][] = new char[n][m];
		for (int i=0;i<n;i++){
			String s = in.nextLine();
			for (int j=0;j<m;j++)
				map[i][j]=s.charAt(j);
		}
		boolean u[] = new boolean[26];
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (map[i][j]==p)
					for (int k=0;k<4;k++){
						int ny = i+dy[k];
						int nx = j+dx[k];
						if (ny>=0 && ny<n &&
							nx>=0 && nx<m &&
							map[ny][nx]!=p && 
							map[ny][nx]!='.')
								u[map[ny][nx]-'A']=true;
					}
		int ans=0;
		for (int i=0;i<26;i++)
			if (u[i])
				ans++;
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
	public char nextChar(){
		return next().charAt(0);
	}
}