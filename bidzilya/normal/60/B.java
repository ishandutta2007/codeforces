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
import java.util.Random;
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
	
	char map[][][];
	boolean u[][][];
	int ans = 0,m,n,k;
	static final int dx[] = {-1,0,0,1,0,0};
	static final int dy[] = {0,1,-1,0,0,0};
	static final int dz[] = {0,0,0,0,-1,1};
	
	void dfs(int z, int y, int x){
		u[z][y][x]=true;
		ans++;
		for (int i=0;i<6;i++){
			int nx = x +dx[i];
			int ny = y +dy[i];
			int nz = z +dz[i];
			if (nx>=0 && nx<m &&
				ny>=0 && ny<n &&
				nz>=0 && nz<k &&
				!u[nz][ny][nx] &&
				map[nz][ny][nx]!='#')
					dfs(nz, ny, nx);
		}
	}
	
	public void solve(){
		k = in.nextInt();
		n = in.nextInt();
		m = in.nextInt();
		map = new char[k][n][m];
		in.nextLine();
		for (int i=0;i<k;i++){
			for (int j=0;j<n;j++){
				String temp = in.nextLine();
				map[i][j] = temp.toCharArray();
			}
			in.nextLine();
		}
		int y = in.nextInt(),
			x = in.nextInt();
		u = new boolean[k][n][m];
		dfs(0,y-1,x-1);
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