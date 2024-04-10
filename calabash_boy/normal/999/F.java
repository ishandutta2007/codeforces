import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "4 3\n" +
            "1 3 2 8 5 5 8 2 2 8 5 2\n" +
            "1 2 2 5\n" +
            "2 6 7\n";
    final int maxn = (int)1e5 + 10;
    int n,k;
    int c1[] = new int[maxn],c2[] = new int[maxn];
    int h[] = new int[maxn];
final int M = 5010;
    long dp[][] = new long[M][M];
    void go(){
        n = ni();
        k = ni();
        for (int i=0;i<n*k;i++){
            int temp = ni();
            c1[temp]++;
        }
        for (int i=0;i<n;i++){
            int temp = ni();
            c2[temp]++;
        }
        for (int i=1;i<=k;i++){
            h[i] = ni();
        }
        for (int i=1;i<=505;i++){
            for (int j=1;j<M;j++){
                dp[i][j] = dp[i-1][j];
                for (int x = 0;x<=k;x++){
                    if(x>j)continue;
                    dp[i][j] = Math.max(dp[i][j],dp[i-1][j-x]+h[x]);
                }
            }
        }
        long ans =0;
        for (int i=0;i<maxn;i++){
            ans+=dp[c2[i]][c1[i]];
        }
        out.println(ans);
    }

    void solve(){
        go();
    }

    void run() throws Exception
    {
        is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        tr(System.currentTimeMillis()-s+"ms");
    }

    public static void main(String[] args) throws Exception { new Main().run(); }

    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;

    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }

    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }

    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }

    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }

    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }

    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        for(;(b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'););
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        for(;;){
            if(Character.isDigit(b)){
                num = num * 10 + (b - '0');
            } else
                return minus ? -num : num;
            b = readByte();
        }
    }

    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        for(;(b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'););
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        for(;;){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    //private boolean oj = true;

    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}