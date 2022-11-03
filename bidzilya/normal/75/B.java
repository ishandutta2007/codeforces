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

	
	public void solve(){
		String iAm = in.nextLine();
		int n =in.nextInt(),m=0;
		String name[] = new String[4*n];
		name[0]=iAm;
		int fr[] = new int[4*n];
		for (int iter=0;iter<n;iter++){
			String name1 = in.next(),
					a1 = in.next();
			int cnt;
			if (a1.equals("posted")){
				cnt = 15;
				in.next();
			}else
			if (a1.equals("commented")){
				cnt = 10;
				in.next();
			}else
				cnt = 5;
			String name2 = in.next();
			name2 = name2.substring(0,name2.length()-2);
			in.next();
			int b1 = -1, b2 = -1;
			for (int i=0;i<=m;i++)
				if (name[i].equals(name1))
					b1 = i;
				else
				if (name[i].equals(name2))
					b2 = i;
			if (b1==-1){
				name[++m]=name1;
				fr[m]=0;
				b1 = m;
			}
			if (b2==-1){
				name[++m]=name2;
				fr[m]=0;
				b2 = m;
			}
			if (b1!=0 && b2!=0)
				continue;
			if (b1==0)
				fr[b2]+=cnt;
			else
				fr[b1]+=cnt;
		}
		for (int i=1;i<=m;i++)
			for (int j=i+1;j<=m;j++)
				if (fr[j]>fr[i] || fr[i]==fr[j] && name[j].compareTo(name[i])<0){
					String buf = name[i];
					name[i]=name[j];
					name[j]=buf;
					int b = fr[i];
					fr[i]=fr[j];
					fr[j]=b;
				}
		for (int i=1;i<=m;i++)
			out.println(name[i]);
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
				tok = new StringTokenizer(buf.readLine()," ");
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