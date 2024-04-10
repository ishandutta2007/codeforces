function main() {
  var n = +nxt();
  var d = [], s = [];
  var qu = [];
  for (var i = -1; ++ i < n; ) {
    d[i] = +nxt();
    s[i] = +nxt();
    if (d[i] === 1) {
      qu.push(i);
    }
  }
  var l = 0;
  var ans = [];
  while (l < qu.length) {
    var u = qu[l ++];
    if (d[u] === 0) continue;
    --d[u];
    ans.push([u, s[u]]);
    s[s[u]] ^= u;
    --d[s[u]];
    if (d[s[u]] === 1) qu.push(s[u]);
  }
  print(ans.length);
  for (var i = -1; ++ i < ans.length; ) {
    print(ans[i][0] + ' ' + ans[i][1]);
  }
}

var line = null, linepos = 0;
function nxt() {
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
    if (typeof print === 'undefined') print = console.log;
    main();
  });
} else main();