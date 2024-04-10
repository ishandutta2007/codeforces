import java.io.*;
import java.util.*;
import java.text.*;
 
 
 
public class Main {
    public static void main(String[] args) {
        Scanner in=new Scanner(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        String d1 = in.nextLine();
        String d2 = in.nextLine();
        SimpleDateFormat format = new SimpleDateFormat("yyyy:MM:dd");
        format.setTimeZone(TimeZone.getTimeZone("UTC"));
        Date date1 = null;
        Date date2 = null;
        try {
            date1 = format.parse(d2);
            date2 = format.parse(d1);
        } catch (Exception e) {
            e.printStackTrace();
        }
        long difference = date1.getTime() - date2.getTime();
        
        long days = difference / (24 * 60 * 60 * 1000);
        out.println(Math.abs(days));
        
        in.close();
        out.close();
    }
 
}