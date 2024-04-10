import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collection;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Map<String, List<String>> hostToPaths = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String s = in.nextToken();
            if (!s.startsWith("http://")) {
                throw new AssertionError();
            }
            s = s.substring(7);
            int pathBegins = s.indexOf('/');
            if (pathBegins < 0) {
                pathBegins = s.length();
            }
            String hostname = s.substring(0, pathBegins);
            String path = s.substring(pathBegins);
            List<String> list = hostToPaths.get(hostname);
            if (list == null) {
                list = new ArrayList<>();
                hostToPaths.put(hostname, list);
            }
            list.add(path);
        }
        Map<List<String>, List<String>> inverse = new HashMap<>();
        for (Map.Entry<String, List<String>> entry : hostToPaths.entrySet()) {
            sortAndUnique(entry.getValue());
            String host = entry.getKey();
            List<String> paths = entry.getValue();
            List<String> hosts = inverse.get(paths);
            if (hosts == null) {
                hosts = new ArrayList<>();
                inverse.put(paths, hosts);
            }
            hosts.add(host);
        }
        int cnt = 0;
        for (List<String> hosts : inverse.values()) {
            if (hosts.size() > 1) {
                ++cnt;
            }
        }
        out.println(cnt);
        for (List<String> hosts : inverse.values()) {
            if (hosts.size() > 1) {
                for (String s : hosts) {
                    out.print("http://" + s + " ");
                }
                out.println();
            }
        }
    }

    void sortAndUnique(List<String> list) {
        Collections.sort(list);
        int last = 0;
        for (int i = 1; i < list.size(); i++) {
            if (!list.get(i).equals(list.get(last))) {
                list.set(++last, list.get(i));
            }
        }
        list.subList(last + 1, list.size()).clear();
    }
}

class InputReader {
    public BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}