var n, i, r, k, x, c, j:int64;
a, b:array[1..200000]of int64;
BEGIN
  r:=0;
  k:=0;
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      if(sqr(round(sqrt(a[i])))=a[i])
        then r:=r+1
        else r:=r-1;
    end;
  if(r>=0)
    then begin
           for i:=1 to n do
             if(sqr(round(sqrt(a[i])))=a[i])and(a[i]>0)and(r>0)
               then begin
                      k:=k+1;
                      r:=r-2;
                    end;
           k:=k+r;
         end
    else begin
           for i:=1 to 200000 do
             b[i]:=0;
           for i:=1 to n do
             begin
               if(sqr(round(sqrt(a[i])))>a[i])
                 then x:=round(sqrt(a[i]))-1
                 else x:=round(sqrt(a[i]));
               c:=a[i]-x*x;
               if(c>sqr(x+1)-a[i])
                 then c:=sqr(x+1)-a[i];
               if(c>0)
                 then b[c]:=b[c]+1;
             end;
           for i:=1 to 200000 do
             for j:=1 to b[i] do
               begin
                 if(r<0)
                   then k:=k+i;
                 r:=r+2;
               end;
         end;
  writeln(k);
END.