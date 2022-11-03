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
    private static final String fileInputName = "input.txt",
                                fileOutputName = "output.txt";
    
    public static void main(String args[]){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FileOutputStream fileOutputStream;
        FileInputStream fileInputStream;
        if (readFromFile){
            try{
                fileInputStream = new FileInputStream(new File(fileInputName));
                fileOutputStream = new FileOutputStream(new File(fileOutputName));
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
    private InputReader in;
    private PrintWriter out;
    private static final Random rnd = new Random();
    int getRandom(int prom){
        return Math.abs(rnd.nextInt())%prom;
    }
    
    public void solve(){
        int n = in.nextInt(),
            m = in.nextInt(),
            r = in.nextInt();
        int dp[][][] = new int[m+1][n][n],
            ans[][][] = new int[n+1][n][n];
        for (int c=0;c<m;c++){
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    dp[c][i][j]=in.nextInt();
            for (int k=0;k<n;k++)
                for (int i=0;i<n;i++)
                    for (int j=0;j<n;j++)
                        dp[c][i][j] = Math.min(dp[c][i][j],dp[c][i][k]+dp[c][k][j]);
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                int min = 0;
                for (int c=1;c<m;c++)
                    if (dp[c][i][j]<dp[min][i][j])
                        min = c;
                ans[0][i][j]=dp[min][i][j];
            }
        for (int iter=1;iter<=n;iter++){
            
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    ans[iter][i][j]=ans[iter-1][i][j];
            for (int k=0;k<n;k++)
                for (int i=0;i<n;i++)
                    for (int j=0;j<n;j++)
                        ans[iter][i][j]=Math.min(ans[iter][i][j], ans[iter-1][i][k]+ans[0][k][j]);
        }
        for (int i=0;i<r;i++){
            int s = in.nextInt(),
                f = in.nextInt(),
                k = in.nextInt();
            s--;f--;
            k = Math.min(k,n);
            out.println(ans[k][s][f]);
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