#include<stdio.h>/*
#include "stdafx.h"*/
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int num;
	vector<int>vec;
	scanf("%d",&num);
	int sum=0;
	for(int i=0;i<num*num;i++)
	{
		int zan;
		scanf("%d",&zan);
		sum+=zan;
		vec.push_back(zan);
	}
	sum/=num;
	printf("%d\n",sum);/*
	sort(vec.begin(),vec.end());*/
	random_shuffle(vec.begin(),vec.end());
	if(num==1)
	{
		printf("%d\n",vec[0]);
	}
	if(num==2)
	{
		printf("%d %d\n%d %d\n",vec[0],vec[1],vec[2],vec[3]);
	}
	if(num==3)
	{
		for(;;)
		{
			if(vec[0]+vec[1]+vec[2]==sum&&vec[3]+vec[4]+vec[5]==sum&&vec[0]+vec[3]+vec[6]==sum&&vec[1]+vec[4]+vec[7]==sum&&vec[0]+vec[4]+vec[8]==sum&&vec[2]+vec[4]+vec[6]==sum)
			{
				printf("%d %d %d\n%d %d %d\n%d %d %d\n",vec[0],vec[1],vec[2],vec[3],vec[4],vec[5],vec[6],vec[7],vec[8]);
				break;
			}
			next_permutation(vec.begin(),vec.end());
		}
	}
	if(num==4)
	{
		for(int j=0;j<16;j++)
		{
			for(int k=0;k<16;k++)
			{
				if(j==k)
				{
					continue;
				}
				for(int l=0;l<16;l++)
				{
					if(j==l||k==l)
					{
						continue;
					}
					for(int m=0;m<16;m++)
					{
						if(j==m||k==m||l==m)
						{
							continue;
						}
						if(vec[j]+vec[k]+vec[l]+vec[m]!=sum)
						{
							continue;
						}
						vector<int>vec2;
						for(int aa=0;aa<16;aa++)
						{
							if(aa==j||aa==k||aa==l||aa==m)
							{
								continue;
							}
							vec2.push_back(vec[aa]);
						}
						for(int n=0;n<12;n++)
						{
							for(int o=0;o<12;o++)
							{
								if(n==o)
								{
									continue;
								}
								for(int p=0;p<12;p++)
								{
									if(n==p||o==p)
									{
										continue;
									}
									for(int q=0;q<12;q++)
									{
										if(n==q||o==q||p==q)
										{
											continue;
										}
										if(vec2[n]+vec2[o]+vec2[p]+vec2[q]!=sum)
										{
											continue;
										}
										vector<int>vec3;
										for(int aa=0;aa<12;aa++)
										{
											if(aa==n||aa==o||aa==p||aa==q)
											{
												continue;
											}
											vec3.push_back(vec2[aa]);
										}
										for(int r=0;r<8;r++)
										{
											for(int s=0;s<8;s++)
											{
												if(r==s)
												{
													continue;
												}
												if(vec[j]+vec2[n]+vec3[r]+vec3[s]!=sum)
												{
													continue;
												}
												for(int t=0;t<8;t++)
												{
													if(r==t||s==t)
													{
														continue;
													}
													if(vec[m]+vec2[p]+vec3[t]+vec3[s]!=sum)
													{
														continue;
													}
													for(int u=0;u<8;u++)
													{
														if(r==u||s==u||t==u)
														{
															continue;
														}
														if(vec[k]+vec2[o]+vec3[t]+vec3[u]!=sum)
														{
															continue;
														}
														vector<int>vec4;
														for(int aa=0;aa<8;aa++)
														{
															if(aa==r||aa==s||aa==t||aa==u)
															{
																continue;
															}
															vec4.push_back(vec3[aa]);
														}
														for(int v=0;v<4;v++)
														{
															for(int x=0;x<4;x++)
															{
																if(v==x)
																{
																	continue;
																}
																if(vec[l]+vec2[p]+vec4[v]+vec4[x]!=sum)
																{
																	continue;
																}
																for(int y=0;y<4;y++)
																{
																	if(v==y||x==y)
																	{
																		continue;
																	}
																	if(vec3[r]+vec3[t]+vec4[v]+vec4[y]!=sum)
																	{
																		continue;
																	}
																	int z=6-v-x-y;
																		if(vec[j]+vec2[o]+vec4[v]+vec4[z]==sum)
																		{
																			printf("%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n",vec[j],vec[k],vec[l],vec[m],vec2[n],vec2[o],vec2[p],vec2[q],vec3[r],vec3[t],vec4[v],vec4[y],vec3[s],vec3[u],vec4[x],vec4[z]);
																			goto l01;
																		}
																	
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
l01:;
}