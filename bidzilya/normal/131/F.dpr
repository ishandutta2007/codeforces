program task_f;

{$APPTYPE CONSOLE}
const nmax = 500;
var map,a,b: array[1..nmax,1..nmax]of integer;
    c: array[0..nmax]of integer;
    n,m,k,t,i,tp,j: integer;
    ch: char;
    ans: int64;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(n,m,k);
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(ch);
      map[i,j]:=ord(ch)-ord('0');
      if (i>2)and(j>2)and
      (map[i-1,j]+map[i-1,j-1]+map[i-1,j-2]+map[i,j-1]+map[i-2,j-1]=5)then
        a[i,j]:=1
      else
        a[i,j]:=0;
      b[i,j]:=a[i,j];
      if (i>1)and(j>1)then
        b[i,j]:=b[i,j]+b[i-1,j]+b[i,j-1]-b[i-1,j-1];
    end;
    readln;
  end;
  ans:=0;
  for i:=1 to n do
    for j:=i+2 to n do begin
      c[0]:=0;
      for t:=1 to m do
        c[t]:=b[j,t]-b[i+1,t];
      tp:=1;
      for t:=1 to m do begin
        while (tp<=t-2)and(c[t]-c[tp+1]>=k)do inc(tp);
        ans:=ans+tp-1;
      end;
    end;
  write(ans);
end.