import java.util.Random;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.File;

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
	
	public void solve(){
		int n = in.nextInt(),
				k = in.nextInt(),
				ans = Integer.MAX_VALUE;
		String s = in.nextLine();
		char m[] = null,
			c[] = s.toCharArray();
		for (int tekC=0;tekC<10;tekC++){
			int ta=0,cnt=0;
			char b[] = new char[n];
			for (int i=0;i<n;i++)
				b[i] = c[i];
label:		for (int d=0;d<10;d++){
				if (tekC+d<10)
					for (int i=0;i<n;i++)
						if (c[i]==(char)(tekC+d+'0')){
							b[i] = (char) (tekC+'0');
							ta += d;
							cnt++;
							if (cnt==k)
								break label; 
						}
				if (d!=0 && tekC-d>=0)
					for (int i=n-1;i>=0;i--)
						if (c[i]==(char)(tekC-d+'0')){
							b[i] = (char)(tekC+'0');
							ta += d;
							cnt++;
							if (cnt==k)
								break label;
						}
			}
			if (ta<ans){
				ans = ta;
				m = b;
			}else
			if (ta==ans){
				if (m==null)
					m = b;
				else{
					boolean men = false;
					for (int i=0;i<n;i++)
						if (b[i]>m[i])
							break;
						else
						if (b[i]<m[i]){
							men = true;
							break;
						}
					if (men)
						m = b;
				}
			}
		}
		out.println(ans);
		out.println(m);
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