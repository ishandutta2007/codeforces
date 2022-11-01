import java.io.*;

public class B {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		s = s.replaceAll("\\.\\.\\. *", " ...");
		s = s.replaceAll(" *,", ", ");
		s = s.replaceAll(" +", " ");
		System.out.println(s.trim());
	}
}