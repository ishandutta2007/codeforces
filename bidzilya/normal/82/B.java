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
		int n=in.nextInt(),countInput=n*(n-1)/2;
		boolean a[][] = new boolean[countInput][];
		for (int i=0;i<countInput;i++){
			int k =in.nextInt();
			a[i]=new boolean[201];
			for (int j=0;j<k;j++)
				a[i][in.nextInt()]=true;
		}
		
		int set[] = new int[201];
		Arrays.fill(set, -1);
		int b = -1;
		for (int i=1;i<=200;i++)
			if (a[0][i]){
				b = i;
				break;
			}
		int countSet = 1;
		set[b]=0;
		for (int i=1;i<countInput;i++)
			if (a[i][b]){
				for (int j=1;j<=200;j++)
					if (a[i][j] && a[0][j]){
						set[j]=0;
						a[i][j]=false;
					}
				int ind =-1;
				for (int j=1;j<=200;j++)
					if (a[i][j] && set[j]!=-1)
						ind = set[j];
				if (ind==-1)
					ind = countSet++;
				for (int j=1;j<=200;j++)
					if (a[i][j])
						set[j]=ind;
			}
		for (int j=1;j<=200;j++)
			if (a[0][j] && set[j]==-1)
				set[j]=countSet;
		countSet++;
		for (int i=0;i<countSet;i++){
			int ans[] = new int[200], m =0;
			for (int j=1;j<=200;j++)
				if (set[j]==i)
					ans[m++]=j;
			if (m==0)continue;
			out.print(m + " ");
			for (int j=0;j<m;j++)
				out.print(ans[j] + " ");
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