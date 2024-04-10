using System;
using System.Collections;
using System.Threading;

class e
{
  ArrayList[] c, s;
  string text;
  int len, cnt = 0;
  int[] p;
  int[,] next;

  void go( int v, int x )
  {
    for (int i = 0; i < c[v].Count; i++)
    {
      int y = x;
      string t = (string)s[v][i];
      for (int j = 0; j < t.Length; j++)
      {
        y = next[y, t[j] - 'a'];
        if (y == len)
          cnt++;
      }
      go((int)c[v][i], y);
    }
  }

  static void Main(string[] args)
  {
    e o = new e();
    Thread oThread = new Thread(new ThreadStart(o.run), 1 << 25);
    oThread.Start();
  }

  void run()
  {
    int n = int.Parse(Console.ReadLine());
    c = new ArrayList[n];
    s = new ArrayList[n];
    for (int i = 0; i < n; i++)
    {
      c[i] = new ArrayList();
      s[i] = new ArrayList();
    }
    for (int i = 1; i < n; i++) 
    {
      string[] tmp = Console.ReadLine().Split(' ');
      int pa = int.Parse(tmp[0]) - 1;
      c[pa].Add(i);
      s[pa].Add(tmp[1]);
    }

    text = Console.ReadLine();
    len = text.Length;
    p = new int[len];
    next = new int[len + 1, 26];
    p[0] = 0;
    for (int i = 0; i < 26; i++)
      next[0, i] = (text[0] == i + 'a' ? 1 : 0);
    for (int x = 1; x < len; x++)
    {
      p[x] = next[p[x - 1], text[x] - 'a'];
      for (int i = 0; i < 26; i++)
        next[x, i] = (text[x] == i + 'a' ? x + 1 : next[p[x - 1], i]);
    }
    for (int i = 0; i < 26; i++)
      next[len, i] = next[p[len - 1], i];
    go(0, 0);
    Console.WriteLine(cnt);
  }
}