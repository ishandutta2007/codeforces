import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class C {
    public static void main(String[] args) throws IOException {
        new C().run();
    }

    private void run() throws IOException {
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        int n = nextInt(in);
        int[] a = new int[n];
        int[] b = new int[n];
        Map<Integer, HashSet<Integer>> map = new HashMap<Integer, HashSet<Integer>>();
        for (int i = 0; i < n; i++) {
            a[i] = nextInt(in);
            b[i] = nextInt(in);
            add(map, a[i], i);
            add(map, b[i], i);
        }
        for (Map.Entry<Integer, HashSet<Integer>> entry : map.entrySet()) {
            if (entry.getValue().size() == 1) {
                int value = entry.getKey();
                int index = (Integer)entry.getValue().toArray()[0];
                while (true) {
                    System.out.print(value + " ");
                    value = a[index] + b[index] - value;
                    final HashSet<Integer> integers = map.get(value);
                    if (integers.size() <= 1) {
                        break;
                    }
                    index = (Integer)integers.toArray()[0] + (Integer)integers.toArray()[1] - index;
                }
                System.out.println(value);
                return;
            }
        }
    }

    private void add(Map<Integer, HashSet<Integer>> map, int a, int i) {
        if (!map.containsKey(a)) {
            map.put(a, new HashSet<Integer>());
        }
        map.get(a).add(i);
    }

    private int nextInt(StreamTokenizer in) throws IOException {
        in.nextToken();
        return (int)in.nval;
    }
}