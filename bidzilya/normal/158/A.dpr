program Task1;

{$APPTYPE CONSOLE}

var n,k,i,ans: integer;
    a: array[1..50]of integer;
begin
    read(n,k);
    for i:=1 to n do read(a[i]);

    ans:=0;
    for i:=1 to n do
      if (a[i]>=a[k])and(a[i]>0)then
        inc(ans);
    write(ans);
end.