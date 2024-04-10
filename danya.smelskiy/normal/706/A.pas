var  a,b,i,n,x,y,t: longint;
    min,dist: extended;
   Begin
    Read(a,b);
    Read(n);
    min:=100000000;
    For i:=1 to n do
     begin
       Read(x,y,t);
       dist:=(sqrt(sqr(x-a)+sqr(y-b)))/t;
       if dist<min then min:=dist;
     end;
     Write(min:0:6);
   End.