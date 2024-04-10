 object Square
   {
      def main(args: Array[String])
       {
           val Array(n,m,a)=readLine.split(" ").map(_.toLong);
           val ans=((n+a-1)/a)*((m+a-1)/a);
           println(ans);
      }
    }