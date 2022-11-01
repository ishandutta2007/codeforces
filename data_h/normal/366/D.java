
import java.util.*;
import java.math.*;;

public class D {
    static int inf = (1 << 30);
    
    static int find(int[] father, int x) {
        return father[x] == x ? x : find(father, father[x]);
    }
    
    public static void main(String arg[]) { 
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        
        edge[] e = new edge[m];
        int[] lower = new int[m];
        int[] father = new int[n];
        
        for(int i = 0; i < m; i++) {
            e[i] = new edge(input.nextInt() - 1, input.nextInt() - 1, input.nextInt(), input.nextInt());
            lower[i] = e[i].l;
        }
        Arrays.sort(e, new ByR());
        Arrays.sort(lower);
        
        int ans = -1;
        for (int low : lower) {
            for(int j = 0; j < n; j++)
                father[j] = j;
            
            int upper = inf;
            
            for(int j = m - 1; find(father, 0) != find(father, n - 1) && j >= 0; j--) {
                if (e[j].l > low)
                    continue;
                if (find(father, e[j].u) != find(father, e[j].v)) {
                    upper = Math.min(upper, e[j].r);
                    father[find(father, e[j].u)] = find(father, e[j].v);
                }
            }
            if (find(father, 0) != find(father, n - 1))
                continue;
            //System.out.println(low + " " +  upper);
            ans = Math.max(ans, upper - low + 1);
        }
        if (ans <= 0) {
            System.out.println("Nice work, Dima!");
        } else {
            System.out.println(ans);
        }
    }
}

class ByR implements Comparator {
    public final int compare(Object a, Object b) {
        int diff =  ((edge)a).r - ((edge)b).r;
        return diff < 0 ? -1 : diff > 0 ? 1 : 0;
    }
};

class edge {
    int u, v, l, r;
    edge(int a, int b, int c, int d) {
        u = a; v = b; l = c; r = d;
    }
};