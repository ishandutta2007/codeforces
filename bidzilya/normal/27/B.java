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
    
    boolean p[][],u[];
    int top[],n,m;
    
    void dfs(int v){
    	u[v]=true;
    	for (int i=0;i<n;i++)
    		if (p[v][i] && !u[i])
    			dfs(i);
    	top[m++]=v;
    }
    
    public void solve(){
    	n = in.nextInt();
    	m = n*(n-1)/2-1;
    	p = new boolean[n][n];
    	int cnt[] = new int[n];
    	for (int i=0;i<m;i++){
    		int a= in.nextInt(),
    			b = in.nextInt();
    		a--;b--;
    		p[a][b]=true;
    		cnt[a]++;cnt[b]++;
    	}
    	int v1=-1,v2=-1;
    	for (int i=0;i<n;i++)
    		if (cnt[i]<n-1){
    			v2 = v1;
    			v1 = i;
    		}
    	top = new int[n];
    	u = new boolean[n];
    	m=0;
    	for (int i=0;i<n;i++)
    		if (!u[i])
    			dfs(i);
    	for (int i=m-1;i>=0;i--)
    		if (top[i]==v1 || top[i]==v2)
    			out.print((top[i]+1)+" ");
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
    
    public String nextLine(){
        try{
            return buf.readLine();
        }catch (IOException e){
            throw new RuntimeException(e);
        }
    }
}