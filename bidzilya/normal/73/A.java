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
    
    public void solve(){
    	int x[] = new int[3];
    	x[0] = in.nextInt();
    	x[1] = in.nextInt();
    	x[2] = in.nextInt();
    	int k = in.nextInt();
    	for (int i=0;i<3;i++)x[i]--;
    	long a[] = new long[3],ans,b[] = new long[3];
    	a[0]=a[1]=a[2]=0;
    	ans = 1;
    	for (int i=1;i<=k;i++){
    		b[0]=(a[1]+1)*(a[2]+1);
    		b[1]=(a[2]+1)*(a[0]+1);
    		b[2]=(a[1]+1)*(a[0]+1);
    		int max = -1;
    		for (int j=0;j<3;j++)
    			if (x[j]>0 && (max==-1 || b[max]<b[j]))
    				max = j;
    		if (max==-1)
    			break;
    		a[max]++;
    		x[max]--;
    		ans += b[max];
    	}
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
    
    public String nextLine(){
        try{
            return buf.readLine();
        }catch (IOException e){
            throw new RuntimeException(e);
        }
    }
}