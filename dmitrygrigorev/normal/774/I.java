import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.lang.String;
public class sas {
	public static ArrayList<String> line;
    public static void main (String args []) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] tokens = in.readLine().split(" ");
		ArrayList<String> line = new ArrayList<String>();
		int n = Integer.parseInt(tokens[0]);
		for (int i=0;i<n;i++){
		    tokens = in.readLine().split(" ");
		    line.add(tokens[0]);
		}
		String our = in.readLine().split(" ")[0];
		int index = 0;
		int aa = 0;
		boolean res = false;
		while (index < our.length()){
		    int mm = 0;
    		for (int i=0;i<n;i++){
    		    int aaa = 0;
    		    String help = line.get(i);
    		    for (int j=0;j<help.length();j++){
    		        char nc = help.charAt(j);
    		        char mc = our.charAt(index);
    		        if (nc == mc){
    		            aaa += 1;
    		            index += 1;
    		            if (index == our.length()){
    		                break;
    		            }
    		        }
    		    }
    		    index = index - aaa;
    		    mm = Math.max(mm, aaa);
    		}
    		index += mm;
    		if (mm == 0){
    		    res = true;
    		    break;
    		}
    		aa += 1;
		}
		if (res){
		    System.out.println(-1);
		}
		else{
		    System.out.println(aa);
		}
		}
}