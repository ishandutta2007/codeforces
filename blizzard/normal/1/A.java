import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		new Main().run();

	}
    int getInt() throws Exception {
    	int a, ans, p;
    	ans = 0;
    	a = System.in.read();
    	while ((a == 13) || (a == 10) || (a == 20) || (a == 32)) {
    			a = System.in.read();
    	}
    	if (a == '-') {
    		p = -1;
    		a = System.in.read();
    	} else p = 1;
    	while ((a != 13) && (a != 10) && (a != 20) &&(a != 32)){
    		ans = ans * 10 + (a - 48);
    		a = System.in.read();
    	}
    	return ans * p;
    }
    private void run() throws Exception {
    	int n, m, a;
    	n = getInt();
    	m = getInt();
    	a = getInt();
    	if (n % a == 0) {
    		n = n / a;
    	} else {
    		n = (n / a) + 1;
    	}
    	if (m % a == 0) {
    		m = m / a;
    	} else {
    		m = (m / a) + 1;
    	}
    	System.out.println((long) n * m);
    }
}