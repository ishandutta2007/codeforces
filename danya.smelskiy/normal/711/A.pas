var a: array[0..1000] of string;
s: string;
   n,i,j: longint;
   t: boolean;
   begin
    Readln(n);
    For i:=1 to n do
     begin
      readln(a[i]);
      s:=a[i];
      if t=false then
      begin
      if (s[1]='O') and (s[2]='O') then
       begin
        s[1]:='+';
        s[2]:='+';
        t:=true;
        a[i]:=s;
       end
      else if (s[4]='O') and (s[5]='O') then
       begin
        s[4]:='+';
        s[5]:='+';
        t:=true;
        a[i]:=s;
       end;
       end;

     end;
     if t=true then writeln('YES')
     else writeln('NO');
     if t=true then
     for i:=1 to n do
      writeln(a[i]);
   End.