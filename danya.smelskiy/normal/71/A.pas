var i,n: longint;
    a: array[1..100] of string;
    s1,s2: string;
    Begin
     ReadLn(n);
     For i:=1 to n do
       begin
        readln(s1);
        if length(s1)<=10 then a[i]:=s1
        else
           begin
              str(length(s1)-2,s2);
              a[i]:=s1[1]+s2+s1[length(s1)];
           end;
       end;
     For i:=1 to n do
       writeln(a[i]);
    End.