   object NextRound
   {
       def readq = readLine().split(" ").map(_.toInt)
       def main(args: Array[String])
       {
           val Array(n,k)=readq;
           val a=readq;
           println(a.count(_>=math.max(a(k-1),1)));
       }
  }