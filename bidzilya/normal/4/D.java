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
	
	Random rnd = new Random();
	int nextRandomInt(int base){
		return Math.abs(rnd.nextInt())%base;
	}
	
	int W[],H[],ind[];
	
	void qsort(int l,int r){
		int i =l,j=r,x=W[i+nextRandomInt(j-i+1)];
		do{
			while (W[i]<x)i++;
			while (W[j]>x)j--;
			if (i<=j){
				int buf = W[i];W[i]=W[j];W[j]=buf;
				buf = H[i];H[i]=H[j];H[j]=buf;
				buf = ind[i];ind[i]=ind[j];ind[j]=buf;
				i++;j--;
			}
		}while (i<=j);
		if (i<r)qsort(i,r);
		if (j>l)qsort(l,j);
	}
	
	public void solve(){
		int n = in.nextInt(),
			w = in.nextInt(),
			h = in.nextInt(),
			d[] = new int[n],
			p[] = new int[n],
			ans[] = new int[n],
			ta = 0;
		W = new int[n];
		H = new int[n];
		ind = new int[n];
		for (int i=0;i<n;i++){
			W[i] = in.nextInt();
			H[i] = in.nextInt();
			ind[i] = i+1;
		}
		qsort(0,n-1);
		for (int i=0;i<n;i++){
			p[i] = -1;
			if (W[i]<=w || H[i]<=h)
				continue;
			d[i]=1;
			for (int j=0;j<i;j++)
				if (W[j]<W[i] && H[j]<H[i] && 
					d[j]+1>d[i]){
					p[i] = j;
					d[i] = d[j]+1;
				}
		}
		
		for (int i=1;i<n;i++)
			if (d[i]>d[ta])
				ta = i;
		int id = ta;
		ta = d[ta];
		for (int i=0;i<ta;i++){
			ans[i] = ind[id];
			id = p[id];
		}
		
		out.println(ta);
		for (int i=ta-1;i>=0;i--)
			out.print(ans[i] + " ");
		
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