program Task2;

{$APPTYPE CONSOLE}

var n,i,j,ans: integer;
    s: array[1..4]of integer;
begin
    read(n);
    fillchar(s,sizeof(s),0);
    for i:=1 to n do begin
        read(j);
        inc(s[j]);
    end;
    ans:=0;
    ans:=ans+s[4];
    while (s[1]>0)and(s[3]>0)do begin
        inc(ans);
        dec(s[1]);
        dec(s[3]);
    end;
    ans:=ans+s[3];
    while (s[2]>0)and(s[1]>1)do begin
        inc(ans);
        dec(s[1],2);
        dec(s[2]);
    end;
    ans:=ans+s[2]div 2;
    s[2]:=s[2]mod 2;
    ans:=ans+s[1]div 4;
    s[1]:=s[1]mod 4;
    j:=s[2]*2 + s[1];
    if (j>0)and(j<=4)then inc(ans)
      else if (j>0)then inc(ans,2);
    write(ans);
end.