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
	
	int t[],k[],n,pe[],ps[],q[][];
	long c[],time[][];
	 
	public void solve(){
		t = new int[3];
		k = new int[3];
		for (int i=0;i<3;i++)
			k[i] = in.nextInt();
		for (int i=0;i<3;i++)
			t[i] = in.nextInt();
		n = in.nextInt();
		n++;
		c = new long[n];
		for (int i=0;i<n-1;i++)
			c[i] = in.nextInt();
		c[n-1]=Math.round(1e15);
		pe = new int[3];
		ps = new int[3];
		q = new int[3][n];
		time = new long[3][n];
		for (int i=0;i<3;i++){
			pe[i]=-1;
			ps[i]=0;
		}
		for (int i=0;i<n;i++){
			int cnt;
			while (ps[0]<=pe[0] && time[0][ps[0]]+t[0]<=c[i]){
				q[1][++pe[1]]=q[0][ps[0]];
				cnt = pe[1]-ps[1]+1;
				if (cnt<=k[1])
					time[1][pe[1]]=time[0][ps[0]]+t[0];
				else{
					cnt = cnt-k[1];
					time[1][pe[1]]=Math.max(time[0][ps[0]]+t[0],time[1][ps[1]+cnt-1]+t[1]);
				}
				ps[0]++;
			}
			while (ps[1]<=pe[1] && time[1][ps[1]]+t[1]<=c[i]){
				q[2][++pe[2]]=q[1][ps[1]];
				cnt = pe[2]-ps[2]+1;
				if  (cnt<=k[2])
					time[2][pe[2]]=time[1][ps[1]]+t[1];
				else{
					cnt = cnt-k[2];
					time[2][pe[2]]=Math.max(time[1][ps[1]]+t[1],time[2][ps[2]+cnt-1]+t[2]);
				}
				ps[1]++;
			}
			while (ps[2]<=pe[2] && time[2][ps[2]]+t[2]<=c[i]){
				c[q[2][ps[2]]]=time[2][ps[2]]+t[2]-c[q[2][ps[2]]];
				ps[2]++;
			}
			q[0][++pe[0]]=i;
			cnt = pe[0]-ps[0]+1;
			if (cnt<=k[0])
				time[0][pe[0]]=c[i];
			else{
				cnt = cnt-k[0];
				time[0][pe[0]]=time[0][ps[0]+cnt-1]+t[0];
			}
		}
		long ans = 0;
		for (int i=0;i<n-1;i++)
			ans = Math.max(ans,c[i]);
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
}