object Word
   {
       def main(args: Array[String])
       {
           val T=readLine().toInt;
           val i=0;
           for(i <- 1 to T)
           {
               val str=readLine().toString();
              if (str.length()<=10)println(str);
              else println(str.charAt(0).toString()+(str.length()-2)+str.charAt(str.length()-1).toString());
  
          }
      }
  }