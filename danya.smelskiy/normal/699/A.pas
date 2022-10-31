var a: array[0..200000] of longint;
    i,j,n,lastright,min: longint;
    t: boolean;
    s1: ansistring;
   Begin
    Readln(n);
    min:=1000000000;
    Readln(s1);
    For i:=1 to n do
    begin
      read(a[i]);
      if (s1[i]='L') and (t=true) then
       begin
        j:=lastright;
        if (a[i]-a[j]) div 2<min then
         begin
          min:=(a[i]-a[j]) div 2;
          if (a[i]-a[j]) mod 2=1 then inc(min);
         end;
       end
      else if s1[i]='R' then
       begin
        t:=true;
        lastright:=i;
       end;
    end;
    if min=1000000000 then Write('-1')
    else Write(min);
   End.