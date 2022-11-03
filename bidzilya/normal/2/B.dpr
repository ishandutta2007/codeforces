program task_1;

{$APPTYPE CONSOLE}
uses Math, SysUtils;
var buf,n,i,j: integer;
    a,a2,a5,t5,t2: array[1..1000,1..1000]of integer;
    ans: string;

    nx,ny: integer;

begin
  read(n);
  nx:=-1;
  for i:=1 to n do
    for j:=1 to n do begin
      read(a[i,j]);
      if (a[i,j]=0)then begin
        a[i,j]:=10;
        nx:=j;
        ny:=i;
      end;
      a2[i,j]:=0;
      a5[i,j]:=0;
      while (a[i,j]mod 2=0)do begin
        inc(a2[i,j]);
        a[i,j]:=a[i,j]div 2;
      end;
      while (a[i,j]mod 5=0)do begin
        inc(a5[i,j]);
        a[i,j]:=a[i,j]div 5;
      end;
    end;
  t2[1,1]:=a2[1,1];
  t5[1,1]:=a5[1,1];
  for i:=2 to n do begin
    t2[1,i]:=t2[1,i-1]+a2[1,i];
    t2[i,1]:=t2[i-1,1]+a2[i,1];
    t5[1,i]:=t5[1,i-1]+a5[1,i];
    t5[i,1]:=t5[i-1,1]+a5[i,1];
  end;
  for i:=2 to n do
    for j:=2 to n do begin
      t2[i,j]:=min(t2[i-1,j],t2[i,j-1])+a2[i,j];
      t5[i,j]:=min(t5[i-1,j],t5[i,j-1])+a5[i,j];
    end;

  if (nx<>-1)and(min(t2[n,n],t5[n,n])>1)then begin
    writeln(1);
    for i:=1 to nx-1 do
      write('R');
    for i:=1 to n-1 do
      write('D');
    for i:=nx to n-1 do
      write('R');
  end else
  if (t2[n,n]<t5[n,n])then begin
    writeln(t2[n,n]);
    ans:='';
    i:=n;j:=n;
    while (i<>1)or(j<>1)do
      if (i>1)and(t2[i,j]=t2[i-1,j]+a2[i,j])then begin
        ans:=ans+'D';
        dec(i);
      end else begin
        ans:=ans+'R';
        dec(j);
      end;
    for i:=length(ans)downto 1 do
      write(ans[i]);
  end else begin
    writeln(t5[n,n]);
    ans:='';
    i:=n;j:=n;
    while (i<>1)or(j<>1)do
      if (i>1)and(t5[i,j]=t5[i-1,j]+a5[i,j])then begin
        ans:=ans+'D';
        dec(i);
      end else begin
        ans:=ans+'R';
        dec(j);
      end;
    for i:=length(ans)downto 1 do
      write(ans[i]);
  end;
end.