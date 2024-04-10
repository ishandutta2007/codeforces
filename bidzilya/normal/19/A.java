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
import java.math.BigInteger;

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
			a[] = new int[n],
			b[] = new int[n],
			c[] = new int[n];
		String name[] = new String[n];
		for (int i=0;i<n;i++)
			name[i] = in.nextLine();
		while (true){
			try{
				if (!in.buf.ready())
					break;
			}catch (IOException e){
				throw new RuntimeException(e);
			}
			String name1 = in.next();
			if (name1==null)
				break;
			String name2 = in.next();
			int cnt1 = in.nextInt(),
				cnt2 = in.nextInt(),
				ind1, ind2;
			ind1=ind2=0;
			for (int i=0;i<n;i++)
				if (name[i].equals(name1))
					ind1 = i;
				else
				if (name[i].equals(name2))
					ind2 = i;
			b[ind1] += cnt1;
			c[ind1] += cnt2;
			b[ind2] += cnt2;
			c[ind2] += cnt1;
			if (cnt1==cnt2){
				a[ind1]++;
				a[ind2]++;
			}else
			if (cnt1>cnt2)
				a[ind1] += 3;
			else
				a[ind2] += 3;
		}
		for (int i=0;i<n;i++){
			int buf = b[i];
			b[i] = b[i]-c[i];
			c[i] = buf;
		}
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				if (a[j]>a[i] ||
					a[j]==a[i] && b[j]>b[i] ||
					a[j]==a[i] && b[j]==b[i] && c[j]>c[i]){
					String s = name[i];name[i]=name[j];name[j]=s;
					int buf = a[i];a[i]=a[j];a[j]=buf;
					buf=b[i];b[i]=b[j];b[j]=buf;
					buf=c[i];c[i]=c[j];c[j]=buf;
				}
		for (int i=0;i<n/2;i++)
			for (int j=i+1;j<n/2;j++)
				if (name[j].compareTo(name[i])<0){
					String s = name[i];name[i]=name[j];name[j]=s;
				}
		for (int i=0;i<n/2;i++)
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
				tok = new StringTokenizer(buf.readLine()," -:");
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
			throw new RuntimeException(e);
		}
	}
}