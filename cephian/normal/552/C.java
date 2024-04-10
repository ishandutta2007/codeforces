import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws NumberFormatException,
            IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int w = Integer.parseInt(tmp[0]), m = Integer.parseInt(tmp[1]);
        boolean ok = true;
        ArrayList<Integer> all = new ArrayList<Integer>();
        while (m != 0) {
            all.add(m % w);
            m /= w;
        }

        for (int i = 0; i < all.size(); ++i) {
            if (all.get(i) == 0 || all.get(i) == 1)
                continue;
            if (all.get(i) == w - 1) {
                int j = i + 1;
                while (j < all.size()) {
                    if (all.get(j) == w - 1) {
                        all.set(j, 0);
                    } else {
                        all.set(j, all.get(j) + 1);
                        break;
                    }
                    ++j;
                }
                continue;
            }
            ok = false;
            break;
        }

        if (ok)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}