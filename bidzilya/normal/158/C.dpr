program Task3;

{$APPTYPE CONSOLE}

var stack: array[1..5000]of string;
    len,i,j,n: integer;
    s: string;
procedure pwd;
begin
    for i:=1 to len do
      write(stack[i],'/');
    writeln;
end;
procedure go1;
var p,pp: integer;
begin
    s:=copy(s,4,length(s)-3)+'/';
    len:=1;
    pp:=1;
    while (true)do begin
        p:=pp+1;
        while (p<=length(s))and(s[p]<>'/')do inc(p);
        if (p-1-pp = 2)and(s[pp+1]='.')and(s[pp+2]='.')then dec(len)
        else if (p<=length(s))and(pp<=length(s))and
                (pp+1<=p-1)then begin
                    inc(len);
                    stack[len]:=copy(s,pp+1,p-1-pp);
                end else break;
        pp:=p;
    end;
end;
procedure go2;
var p,pp: integer;
begin
    s:=copy(s,4,length(s)-3)+'/';
    pp:=0;
    while (true)do begin
        p:=pp+1;
        while (p<=length(s))and(s[p]<>'/')do inc(p);
        if (p-1-pp = 2)and(s[pp+1]='.')and(s[pp+2]='.')then dec(len)
        else if (p<=length(s))and(pp<=length(s))and
                (pp+1<=p-1)then begin
                    inc(len);
                    stack[len]:=copy(s,pp+1,p-1-pp);
                end else break;
        pp:=p;
    end;
end;
procedure cd;
begin
    if (s[4]='/')then go1
      else go2;
end;
begin
    //reset(input, 'input.txt');
    //rewrite(output, 'output.txt');
    len:=1;
    stack[1]:='';

    readln(n);
    for n:=1 to n do begin
        readln(s);
        if (s[1]='c')and(s[2]='d')then cd
          else pwd;
    end;
end.