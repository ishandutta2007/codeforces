function main() {
  var n = +next(), m = +next();
  if (m != n - 1) {
    print("no");
    return;
  }
  var p = [];
  var i;
  for (i = -1; ++ i < n; ) p[i] = i;
  function findp(u) { return (p[u] = u === p[u] ? u : findp(p[u])); }
  function join(u, v) { p[findp(u)] = findp(v); }
  
  while (m--) { 
    join(next() - 1, next() - 1);
  }
  var cnt = 0;
  for (i = -1; ++i < n; )
    cnt += +(i === findp(i));
  print(cnt === 1 ? "yes" : "no");
}

var line = null, linepos = 0;
function next() {
  if (!line || linepos === line.length) {
    line = readline().split(' ');
    linepos = 0;
  }
  return line[linepos++];
}

if (typeof readline == 'undefined') {
  process.stdin.resume();
  process.stdin.setEncoding('ascii');
  
  var input_stdin = "";
  process.stdin.on('data', function (data) { input_stdin += data; });
  process.stdin.on('end', function () {
    // input_stdin = input_stdin.split(/\s/);
    input_stdin = input_stdin.split('\n');
    var curline = 0;
    readline = () => input_stdin[curline++];
    if (typeof print == 'undefined') print = console.log;
    main();
  });
} else main();