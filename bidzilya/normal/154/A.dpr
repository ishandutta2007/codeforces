program task_3;

{$apptype console r+ q+}
uses SysUtils, Math;
var c1,c2: char;
    s: string;
    i,j,k,t,ans: integer;

procedure check(l,r: integer);
var i,t1,t2: integer;
begin
  t1:=0;t2:=0;
  for i:=l to r do
    if (s[i]=c1)then inc(t1)else inc(t2);
  ans:=ans+min(t1,t2);
end;

begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(s);
  readln(k);
  ans:=0;
  for k:=1 to k do begin
    readln(c1,c2);
    i:=1;
    while (i<=length(s))do begin
      if (s[i]=c1)or(s[i]=c2)then begin
        j:=i;
        while (i+1<=length(s))and((s[i+1]=c1)or(s[i+1]=c2))do inc(i);
        check(j,i);
      end;
      inc(i);
    end;
  end;
  write(ans);
end.